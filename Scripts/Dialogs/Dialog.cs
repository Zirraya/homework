using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[System.Serializable]

public class Dialog 
{
    public string name;
    [TextArea(3, 10)] // минимальное и максимальное кол-во строк текста
    public string[] sentences; // массив предложения
}
