package com.example.yasser.bluetoothcontrolledcar;

import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothManager;
import android.content.Context;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CheckBox;
import android.widget.Checkable;
import android.widget.CompoundButton;
import android.widget.Switch;

public class Main2Activity extends AppCompatActivity {
    BluetoothDevice bluetoothDevice;
    BluetoothManager bluetoothManager;
    ConnectBluetooth connectBluetooth;


    Switch switchbutton;
    CheckBox checkBox;

    boolean connect = false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
        Intent intent = getIntent();

        switchbutton = (Switch) findViewById(R.id.switch1);
        checkBox = (CheckBox) findViewById(R.id.checkBox);
        String address = intent.getStringExtra("connection");
        bluetoothManager = (BluetoothManager) getSystemService(Context.BLUETOOTH_SERVICE);
        BluetoothAdapter mBluetoothAdapter = bluetoothManager.getAdapter();

        bluetoothDevice = mBluetoothAdapter.getRemoteDevice(address);
        connectBluetooth = new ConnectBluetooth(bluetoothDevice);
        connect = connectBluetooth.Connect(getApplicationContext());
if(!connect){
    Intent i = new Intent(this,MainActivity.class);
    startActivity(i);
    this.finish();
}
    checkBox.setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View v) {
    if(connect){
        if(checkBox.isChecked()) connectBluetooth.SendControl(getApplicationContext(),7);
        else connectBluetooth.SendControl(getApplicationContext(),8);
    }
    }
    });

        switchbutton.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(connect){
                    if(isChecked) {
                        connectBluetooth.SendControl(getApplicationContext(), 1);
                    }else{
                        connectBluetooth.SendControl(getApplicationContext(), 0);
                    }
                }
            }
        });

    }
    public void Up(View v){if(connect) connectBluetooth.SendControl(getApplicationContext(), 3); }
    public void Down(View v){if(connect) connectBluetooth.SendControl(getApplicationContext(), 6); }
    public void  Right(View v){ if(connect) connectBluetooth.SendControl(getApplicationContext(), 5); }
    public void Left(View v){ if(connect) connectBluetooth.SendControl(getApplicationContext(), 4); }

}
