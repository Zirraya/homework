using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Drop : MonoBehaviour
{
    public GameObject item;
    private Transform player;

    private void Start()
    {
        player = GameObject.FindGameObjectWithTag("Player").transform;
    }


    public void SpawnDroppedItem()
    {
        Vector2 playerPos = new Vector2(player.position.x + 10, player.position.y + 5); // �������������� �������� ����� �������
        Instantiate(item, playerPos, Quaternion.identity); // ��������� ������� �� �������
    }
}
