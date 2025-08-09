using UnityEngine;

public class PickUpItems : MonoBehaviour
{
    public InvenoryManager inventoryManager;
    public Item[] itemsToPickUp;


    public void Pickupitem(int id)
    {
        bool result=inventoryManager.AddItem(itemsToPickUp[id]);
        if (result is true)
        {
            Debug.Log("Да");
        }
        else
        {
            Debug.Log("Нет");

        }


        
       

    }
}
