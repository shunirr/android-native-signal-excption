package jp.s5r.android.signal;

import android.app.Activity;
import android.os.Bundle;

public class TestActivity extends Activity
{
    static
    {
        System.loadLibrary("test");
    }

    public native void nativeMethod() throws RuntimeException;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        nativeMethod();
    }
}
