//xml
<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:tools="http://schemas.android.com/tools"
    android:id="@android:id/tabhost"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="horizontal">

        <EditText
            android:id="@+id/edtUrl"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:layout_weight="1"
            android:singleLine="true" />
        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:id="@+id/btnGo"
            android:text="이동"/>
        <Button
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:id="@+id/btnBack"
            android:text="이전"/>
    </LinearLayout>
    <WebView
        android:id="@+id/webView1"
        android:layout_width="match_parent"
        android:layout_height="wrap_content"></WebView>

</LinearLayout>

//java
package com.example.swuksr.myapplication;
import android.app.Activity;
import android.app.TabActivity;
import android.os.Bundle;
import android.view.View;
import android.webkit.WebResourceRequest;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TabHost;
import android.widget.TabHost.TabSpec;

@SuppressWarnings("deprecation")
public class MainActivity extends Activity {
    EditText edtUrl;
    Button btnGo,btnBack;
    WebView web;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        edtUrl = (EditText) findViewById(R.id.edtUrl);
        btnBack = (Button) findViewById(R.id.btnBack);
        btnGo = (Button) findViewById(R.id.btnGo);
        web = (WebView) findViewById(R.id.webView1);

        web.setWebViewClient(new CookwebViewClient());

        WebSettings webSet = web.getSettings();
        webSet.setBuiltInZoomControls(true);

        btnGo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                web.loadUrl(edtUrl.getText().toString());
            }
        });
        btnBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                web.goBack();
            }
        });
    }
    class CookwebViewClient extends WebViewClient{
            @Override
        public boolean shouldOverrideUrlLoading(WebView view, WebResourceRequest request) {
            return super.shouldOverrideUrlLoading(view, request);
        }
    }


}


//menifest에 인터넷 허용하는 코드 추가 
//<uses-permission android:name="android.permission.INTERNET"></uses-permission> 
