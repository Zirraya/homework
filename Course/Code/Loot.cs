using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Loot : MonoBehaviour
{


    [SerializeField] private Item _item;
    private bool _isCollected = false; 

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("Player"))
        {
            if (_isCollected) return;
            _isCollected = true;
            bool canAdd = InvenoryManager.instance.AddItem(_item);

            if (canAdd)
            {
                Destroy(gameObject);
            }
           
        }    
    }

  

}
