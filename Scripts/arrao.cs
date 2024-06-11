using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class arrao : MonoBehaviour
{
    public float speed = 70f; // скорость стрелы
    public Rigidbody2D rb;

    void Start()
    {
        rb.velocity = transform.right * speed; // движение стрелы
        Destroy(gameObject, 0.4f);
        
    }

    private void OnTriggerEnter2D(Collider2D hitinfo) // метод для уничтоженя врага
    {
        Obstacle enemy = hitinfo.GetComponent<Obstacle>();
        Flight _ = hitinfo.GetComponent<Flight>();
        if (enemy !=null)
        {
            enemy.TakeDamage(1);

        }
        Destroy(gameObject);
    }

        


}
