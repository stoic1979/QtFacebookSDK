/*
 *  This file is part of SocialDashboard.
 *
 *  SocialDashboard is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  SocialDashboard is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SocialDashboard.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  ------------------------------------------------------------------------------
 *     About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
 *    Author: Navjot Singh
 *   Website: www.weavebytes.com
 *  ------------------------------------------------------------------------------
 */

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

        FB->GetAccessToken(FB_ACCESS_TOKEN_URL);
    }
}


