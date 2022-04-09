package com.example.breathalyzerapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.view.View;
import android.content.Intent;
import android.net.Uri;

public class MainActivity extends AppCompatActivity {

    Button activate;
    EditText phone;
    EditText name;
    String number;
    String person;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        activate = findViewById(R.id.active);
        phone = findViewById(R.id.phoneNumber);
        name = findViewById(R.id.name);
        activate = findViewById(R.id.active);
        phone = findViewById(R.id.phoneNumber);
        name = findViewById(R.id.name);

    }
    public void sendMessage(View view) {
        number = String.format("smsto: %s", phone.getText().toString());
        person = name.getText().toString();
        String output = "Hey, " + person + ", I am in a bit of a situation here. I am not in condition to drive back home. Could you pick me up from the bar? Thanks.";
        Intent smsIntent = new Intent(Intent.ACTION_SENDTO);
        smsIntent.setData(Uri.parse(number));
        smsIntent.putExtra("sms_body", output);
            startActivity(smsIntent);
    }
}