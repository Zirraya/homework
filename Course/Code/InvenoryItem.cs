using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;
using Unity.VisualScripting;

public class InvenoryItem : MonoBehaviour, IBeginDragHandler, IDragHandler, IEndDragHandler
{

    [Header("UI")]
    public Image image;
    public Text countText;

    [UnitHeaderInspectable] public Item item;
    [UnitHeaderInspectable] public int count = 1;
    [HideInInspector] public Transform parentAfterDrag;

  

    public void InitialiseItem(Item newItem, Canvas canvas)
    {
        _canvas= canvas;
        item = newItem;
        image.sprite= newItem.image;
        RefreshCount();
    }

    public void RefreshCount()
    {
    countText.text=count.ToString();
        bool textActive = count > 1;
        countText.gameObject.SetActive(textActive);

    }

   [SerializeField] RectTransform rectTransform;
   [SerializeField] Canvas _canvas;
    public void OnBeginDrag(PointerEventData eventData) 
    {
        image.raycastTarget = false;
        parentAfterDrag=transform.parent;
        transform.SetParent(transform.root);
    
    }
    public void OnDrag(PointerEventData eventData)
    {
        rectTransform.anchoredPosition += eventData.delta / _canvas.scaleFactor;

    }
    public void OnEndDrag(PointerEventData eventData) 
    {
        image.raycastTarget = true;
        transform.SetParent(parentAfterDrag);
    }

}
