#ifndef QTEDITOR_H
#define QTEDITOR_H

#include <QMainWindow>
#include <QPainter>

class QAction;
class QMdiArea;
class QTextEdit;
class QFontComboBox;
class QDoubleSpinBox;

class QtEditor : public QMainWindow
{
    Q_OBJECT

public:
    QtEditor(QWidget *parent = nullptr);
    ~QtEditor();

private:
    QMap<QTextEdit*, QString> filePathMap;
    QMdiArea* mdiArea;
//    QTextEdit *textedit;
    QFontComboBox* fontComboBox;
    QDoubleSpinBox* sizeSpinBox;

    QAction *makeAction(QString icon, QString name, QString shortCut, \
                        QString toolTip, QObject* recv, const char* slot);

public slots:
    /* File Menu */
    void newFile( );
    void openFile( );
    void saveFile( );
    void saveAsFile( );
    void print( );

    /* Edit Menu */
    void undo( );
    void redo( );
    void copy( );
    void cut( );
    void paste( );
    void zoomIn( );
    void zoomOut( );

    /* Format Menu */
    void setFont( );
    void setColor( );
    void alignText( );

    void setCurrentFont(const QFont&);
    void setFontPointSize(qreal);

    void setFontWidget( );

};
#endif // QTEDITOR_H
