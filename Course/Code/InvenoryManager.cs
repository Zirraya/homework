using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InvenoryManager : MonoBehaviour
{
    public static InvenoryManager instance;
    public int maxStackItems = 5;
    public InventorySlot[] inventorySlots;
    public GameObject inventoryItemPrefab;
    [SerializeField] private Canvas _canvas;


    private void Awake()
    {
        instance=this;
    }


    public bool AddItem(Item item)
    {
        // Check slot
        for (int i = 0; i < inventorySlots.Length; i++)
        {
            InventorySlot slot = inventorySlots[i];
            InvenoryItem itemSlot = slot.GetComponentInChildren<InvenoryItem>();
            if (itemSlot is not null &&
                itemSlot.item==item &&
                itemSlot.count<maxStackItems &&
                itemSlot.item.stackbale==true)
            {
               itemSlot.count++;
                itemSlot.RefreshCount();
                return true;
            }
        }
        //
    
        // Check free slot
        for(int i=0;i<inventorySlots.Length;i++) 
        { 
            InventorySlot slot = inventorySlots[i];
            InvenoryItem itemSlot=slot.GetComponentInChildren<InvenoryItem>();
            if(itemSlot is null) 
            {
                SpawnNewItem(item,slot);
                return true;
            }
        }
        return false;   
        //
    }
    void SpawnNewItem(Item item, InventorySlot slot) 
    {
        GameObject newItemGo = Instantiate(inventoryItemPrefab, slot.transform);
        InvenoryItem inventoryItem = newItemGo.GetComponent<InvenoryItem>();
        inventoryItem.InitialiseItem(item,_canvas);

    }
}
