using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fire : MonoBehaviour
{
    [SerializeField] private float speed; // сериализованные поля ставлстя чтобы можно было переменные настроить из unity
    private bool hit;

    private CircleCollider2D col;
    private float direction; // поплавок поможет опрделить в какую сторону летит объект
    private Animator anim;

    private void Awake()
    {
        anim = GetComponent<Animator>();
        col = GetComponent<CircleCollider2D>();
    }

    private void Update()
    {
        if (hit) return;
        float movementSpeed = speed * Time.deltaTime*direction;
        transform.Translate(movementSpeed, 0, 0);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        hit = true;
        col.enabled = false;
    }

    // метод для полета огненного шара
    public void SetDirection(float _direction)
    {
        direction = _direction;
        gameObject.SetActive(true);
        hit = false;
        col.enabled = true;
        Destroy(gameObject, 0.4f);

    }



}
