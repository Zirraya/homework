using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class arrao : MonoBehaviour
{
    public float speed = 70f; // �������� ������
    public Rigidbody2D rb;

    void Start()
    {
        rb.velocity = transform.right * speed; // �������� ������
        Destroy(gameObject, 0.4f);
        
    }

    private void OnTriggerEnter2D(Collider2D hitinfo) // ����� ��� ���������� �����
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
