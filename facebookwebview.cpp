#include <QUrlQuery>

#include "facebook.h"
#include "facebookwebview.h"

using namespace nsFacebook;

FacebookWebView::FacebookWebView(QWidget *parent) :
    QWebEngineView(parent)
{
    connect(this, SIGNAL( urlChanged(const QUrl&) ),
            this,   SLOT( WebViewUrlChanged(const QUrl&) )
            );

    // showing webview in UI on parent widget
    show();
}

void FacebookWebView::LoginAndGetAccessToken() {
    load(FB_OAUTH_URL);
}

void FacebookWebView::WebViewUrlChanged(const QUrl& url) {

    if(url.toString().startsWith(FB_SUCCESS_URL)) {

        QUrlQuery query(url);
        QString code = query.queryItemValue("code");
        FB_SET_ACCESS_CODE(code);

        GetFacebookAccessToken(FB_ACCESS_TOKEN_URL);
    }
}

void FacebookWebView::GetFacebookAccessToken(QUrl url) {
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(ReplyFinished(QNetworkReply*)));

    // creating get request
    QNetworkRequest request;
    request.setUrl(url);
    request.setRawHeader("User-Agent", "Some-Browser 1.0");

    manager->get(request);
}

void FacebookWebView::ReplyFinished(QNetworkReply *reply) {
    qDebug() << "[FacebookWebView] got network reply";

    // Getting the http status code
    int HttpStatusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "[FacebookWebView] HttpStatusCode: " << HttpStatusCode;

    bool error = false;
    QString respData;

    if (reply->error() == QNetworkReply::NoError) {
        respData = reply->readAll();
    }
    else {
        error = true;
        respData = reply->errorString();
        qDebug() << "[FacebookWebView] reply content:-\n" << reply->readAll();

    }
    delete reply;

    emit GotFacebookAccessToken(error, respData);
}
