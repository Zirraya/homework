using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slot : MonoBehaviour
{
    private Inventory inventory;
    public int i;


    private void Start()
    {
        inventory = GameObject.FindGameObjectWithTag("Player").GetComponent<Inventory>();
    }

    // Update is called once per frame
    private void Update()
    {
        if(transform.childCount <= 0)
        {
            inventory.isFull[i] = false;
        }
    }

    public void DropItem()
    {
        foreach(Transform childe in transform)
        {
            childe.GetComponent<Drop>().SpawnDroppedItem(); // предмет после удаления из инвенторя возвращается на локацию
            GameObject.Destroy(childe.gameObject); // уничтожаем из инвенторя

        }
    }

}
