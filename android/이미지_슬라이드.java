//activity_main.xml
<?xml version="1.0" encoding="utf-8"?>

<LinearLayout xmlns:android="http://schemas.android.com/apk/res/android"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:orientation="vertical">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="vertical">

        <Button
            android:id="@+id/btnPrev"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:text="Button" />

        <Button
            android:id="@+id/btnNext"
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:text="Button" />

    </LinearLayout>

    <ViewFlipper
        android:id="@+id/viewFlipper"
        android:layout_width="match_parent"
        android:layout_height="match_parent">

        <ImageView
            android:id="@+id/imgView"
            android:layout_width="match_parent"
            android:layout_height="match_parent"
            android:background="#42c642"
            android:orientation="vertical" />

        <ImageView
            android:layout_width="match_parent"
            android:layout_height="match_parent"
            android:background="#e112c5"
            android:orientation="vertical" />

        <ImageView
            android:layout_width="match_parent"
            android:layout_height="match_parent"
            android:background="#06020a"
            android:orientation="vertical" />

    </ViewFlipper>
</LinearLayout>
//MainActivity.java
package com.example.swuksr.myapplication;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.ViewFlipper;

import java.io.BufferedInputStream;
import java.io.InputStream;
import java.net.URL;
import java.net.URLConnection;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnPrev, btnNext;
        final ViewFlipper vFlipper;

        btnPrev=(Button)findViewById(R.id.btnPrev);
        btnNext=(Button)findViewById(R.id.btnNext);
        vFlipper=(ViewFlipper)findViewById(R.id.viewFlipper);

        btnPrev.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                vFlipper.startFlipping();
                vFlipper.setFlipInterval(500);
            }
        });

        btnNext.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                vFlipper.stopFlipping();
            }
        });
    }
}

