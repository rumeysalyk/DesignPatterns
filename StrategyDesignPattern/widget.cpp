#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->setFixedSize(500, 500);
    this->setStyleSheet("background-color: #D7E4C0;");

    BankSelection = new QComboBox(this);
    BankSelection->setGeometry(50, 50, 100, 30);
    BankSelection->addItem("Seçiniz");
    BankSelection->setItemData(0, QVariant(false), Qt::UserRole - 1); // Qt::UserRole - 1, özel bir kullanıcı rolüdür
    BankSelection->addItem("Ziraat Bank");
    BankSelection->addItem("Vakıf Bank");
    BankSelection->setEnabled(true);
    BankSelection->setStyleSheet("QComboBox { color: black; selection-background-color: #789461; }");

    // Özel bir QStyledItemDelegate oluştur ve QComboBox'un görünümüne ayarla
    itemDelegate = new CustomItemDelegate(BankSelection);
    BankSelection->setItemDelegate(itemDelegate);

    SelectButton = new QPushButton(this);
    SelectButton->setText("Select");
    SelectButton->setEnabled(false);
    SelectButton->setGeometry(230, 50, 75, 30);
    SelectButton->setStyleSheet("color: black; background-color: #B6BBC4;");

    CalculateButton = new QPushButton(this);
    CalculateButton->setText("Calculate");
    CalculateButton->setEnabled(false);
    CalculateButton->hide();
    CalculateButton->setGeometry(230, 100, 75, 30);
    CalculateButton->setStyleSheet("color: black; background-color: #B6BBC4;");
    connect( CalculateButton, SIGNAL(pressed()), this, SLOT( Calculate()) );

    QObject::connect(SelectButton, &QPushButton::clicked, [this](){
        QString selectedItem = BankSelection->currentText();
        qDebug() <<"Test: " << selectedItem;
        ShowSelectedBank();
    });

    QObject::connect(BankSelection, QOverload<int>::of(&QComboBox::activated), [this](int index){
        QString selectedItem = BankSelection->itemText(index);
        SelectButton->setStyleSheet("color: black; background-color: #789461;");
        SelectButton->setEnabled(true);
        qDebug() << selectedItem;
    });

    CapitalLine = new QLineEdit(this);
    CapitalLine->setGeometry(50, 100, 150, 30);
    CapitalLine->setPlaceholderText("Enter capital amount");
    CapitalLine->hide();

    InterestLabel = new QLabel(this);
    InterestLabel->hide();
    InterestLabel->setGeometry(50, 150, 150, 30);
    InterestLabel->setStyleSheet("color: black; background-color: #B0A695");

    connect(CapitalLine, &QLineEdit::textChanged, this, &Widget::EnableCalculateButton);

    QIntValidator *validator = new QIntValidator(0, 10000, this);
    CapitalLine->setValidator(validator);
}

Widget::~Widget()
{
}

void Widget::ShowSelectedBank()
{
    CalculateButton->show();
    CapitalLine->clear();
    CapitalLine->show();
    SetBankConfiguration( BankSelection->currentIndex() );
}

void Widget::SetBankConfiguration(int a_index)
{
    qDebug() << a_index;
    if( a_index == 1 )
    {
        BankConfiguration = new ZiraatBank();
    }
    else if( a_index == 2 )
    {
        BankConfiguration = new VakifBank();
    }
    else
    {
        qDebug() << "Error";
    }
}

int Widget::GetCapital()
{
    bool ok;
    int number = CapitalLine->text().toInt(&ok);

    if (!ok)
    {
        QMessageBox::warning(this, "Input Error", "Please enter a valid number.");
        return qQNaN();
    }

    return number;
}

void Widget::Calculate()
{
    float interest = BankConfiguration->CalculateInterest(GetCapital());
    InterestLabel->setText( QString(" Interest:") + QString::number( interest ));
    InterestLabel->show();
}

void Widget::EnableCalculateButton()
{
    QString text = CapitalLine->text();
    if (!text.isEmpty())
    {
        CalculateButton->setEnabled(true);
        CalculateButton->setStyleSheet("color: black; background-color: #789461;");
    }
    else
    {
        CalculateButton->setEnabled(false);
        CalculateButton->setStyleSheet("color: black; background-color: #B6BBC4;");
    }
}



