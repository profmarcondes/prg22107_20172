#include <QtWidgets>

int main(int argc, char * argv[]){
	QApplication app(argc, argv);

    QWidget *janela = new QWidget();
    janela->setWindowTitle("My Precious");

    QPushButton * button = new QPushButton("QUIT");
    QObject::connect(button, SIGNAL(clicked(bool)), &app, SLOT(quit()));

    QLabel *hello = new QLabel("<h1><font color='red'>Hello</font> QT!</h1>");
    QLabel *goodbye = new QLabel("<h1><font color='red'>Good bye</font> QT!</h1>");

    QHBoxLayout *top_layout = new QHBoxLayout();
    top_layout->addWidget(hello);
    top_layout->addWidget(goodbye);

    QVBoxLayout *main_layout = new QVBoxLayout();
    main_layout->addLayout(top_layout);
    main_layout->addWidget(button);

    janela->setLayout(main_layout);

    janela->show();

	return app.exec();
}
