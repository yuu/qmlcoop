#include <QObject>
#include <QString>
#include <QDebug>

class message : public QObject
{
    Q_OBJECT

public:
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    void setName(const QString &a)
    {
        if (a != m_name) {
            m_name = a;
            emit nameChanged();
        }
    }

    QString name() const
    {
        return m_name;
    }

    Q_INVOKABLE void setName(QString &name);
    Q_INVOKABLE QString Name() const;

signals:
    void nameChanged();

public slots:
    void debugPrintSlot(const QString msg)
    {
        qDebug() << msg;
    }

private:
    QString m_name;
};
