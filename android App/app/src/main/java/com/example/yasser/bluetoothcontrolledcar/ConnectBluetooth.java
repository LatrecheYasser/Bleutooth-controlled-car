package com.example.yasser.bluetoothcontrolledcar;

import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.content.Context;
import android.widget.Toast;


import java.io.IOException;
import java.io.OutputStream;
import java.io.Serializable;

import java.util.UUID;

public class ConnectBluetooth implements Serializable {

    private final BluetoothSocket mmSocket;
    private final BluetoothDevice mmDevice;
    private  OutputStream mmOutStream ;

    static final UUID MY_UUID = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB");

    public ConnectBluetooth(BluetoothDevice device) {
        // Use a temporary object that is later assigned to mmSocket
        // because mmSocket is final.
        BluetoothSocket tmp = null;
        mmDevice = device;

        try {
            // Get a BluetoothSocket to connect with the given BluetoothDevice.
            // MY_UUID is the app's UUID string, also used in the server code.

            tmp = device.createRfcommSocketToServiceRecord(MY_UUID);
        } catch (IOException e) {
            //Log.e(TAG, "Socket's create() method failed", e);
        }
        mmSocket = tmp;
    }


    public boolean Connect(Context context) {
        OutputStream tmpOut = null;

        try {
            // Connect to the remote device through the socket. This call blocks
            // until it succeeds or throws an exception.
            mmSocket.connect();
            tmpOut = mmSocket.getOutputStream();
            Toast.makeText(context,"Connected",Toast.LENGTH_LONG).show();

            mmOutStream = tmpOut;

            return true;
        } catch (IOException connectException) {
            Toast.makeText(context,"Can't Connect",Toast.LENGTH_LONG).show();
            // Unable to connect; close the socket and return.
            try {
                mmSocket.close();
            } catch (IOException closeException) {
                //Log.e(TAG, "Could not close the client socket", closeException);
            }

        }

        // The connection attempt succeeded. Perform work associated with
        // the connection in a separate thread.

    return false;
    }

    // Closes the client socket and causes the thread to finish.
    public void cancel() {
        try {
            mmSocket.close();
        } catch (IOException e) {
           // Log.e( "Could not close the client socket", e);
        }
    }

    public void SendControl(Context context,int i) {
       try {
           mmOutStream.write(i);
       }catch (Exception e){

       }

    }
}
