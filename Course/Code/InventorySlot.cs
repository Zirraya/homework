using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using Unity.VisualScripting;

public class InventorySlot : MonoBehaviour, IDropHandler
{
    public void OnDrop(PointerEventData eventData)
    {
        if (transform.childCount == 0)
        {
            InvenoryItem invenoryItem = eventData.pointerDrag.GetComponent<InvenoryItem>();
            invenoryItem.parentAfterDrag = transform;
        }
    }
}
