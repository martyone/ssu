/**
 * @file rndssucli.h
 * @copyright 2012 Jolla Ltd.
 * @author Bernd Wachter <bernd.wachter@jollamobile.com>
 * @date 2012
 */

#ifndef _RndSsuCli_H
#define _RndSsuCli_H

#include <QObject>
#include <QSettings>
#include <QStringList>
#include <QDebug>

#include "libssu/ssu.h"
#include "ssuproxy.h"

class RndSsuCli: public QObject {
    Q_OBJECT

  public:
    RndSsuCli();
    ~RndSsuCli();

  public slots:
    void run();

  private:
    Ssu ssu;
    SsuProxy *ssuProxy;
    QSettings settings;
    int state;
    void usage();
    void uidWarning(QString message="");
    void optDomain(QStringList opt);
    void optFlavour(QStringList opt);
    void optMode(QStringList opt);
    void optModel(QStringList opt);
    void optModifyRepo(int action, QStringList opt);
    void optRegister(QStringList opt);
    void optRelease(QStringList opt);
    void optRepos(QStringList opt);
    void optStatus();
    void optUpdateCredentials(QStringList opt);
    void optUpdateRepos();

    enum Actions {
      Remove  = 0,
      Add     = 1,
      Disable = 2,
      Enable  = 3,
    };

    enum State {
      Idle,
      Busy,
      UserError
    };

  private slots:
    void handleResponse();
    void handleDBusResponse();

  signals:
    void done();

};

#endif
