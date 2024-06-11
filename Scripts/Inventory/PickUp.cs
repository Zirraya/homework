using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PickUp : MonoBehaviour
{
    private Inventory inventory;
    public GameObject slotButton;


    private void Start()
    {
        inventory = GameObject.FindGameObjectWithTag("Player").GetComponent<Inventory>();
    }


    private void OnTriggerEnter2D(Collider2D other) // Работает когда игрок взаимодействует с предметом
    {
        if (other.CompareTag("Player"))
        {
            for(int i = 0; i < inventory.slots.Length; i++)  // i это слот интвенторя, он пробегается по всем слотам
            {
                if (inventory.isFull[i] == false)  // есть ли предмет в слоте, если нет то идет заполнение
                {
                    inventory.isFull[i] = true;
                    Instantiate(slotButton, inventory.slots[i].transform); // создание предмета в инвентаре
                    Destroy(gameObject); // уничтожение предмета на локации
                    break;
                }
            }
        }
    }
}
