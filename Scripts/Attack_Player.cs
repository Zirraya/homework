using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Attack_Player : MonoBehaviour
{
    [SerializeField] private float attackCoolDown;
    private Animator anim;
    private Hero hero;
    private float cooldownTimer = Mathf.Infinity;

    private void Awake()
    {
        anim = GetComponent<Animator>();
        hero = GetComponent<Hero>();
    }

    private void Update()
    {
        if (Input.GetButtonDown("Fire1") && cooldownTimer > attackCoolDown)
            Attack();

        cooldownTimer += Time.deltaTime;
        
    }

    private void Attack()
    {
        anim.SetTrigger("attacka");
        cooldownTimer = 0;
        
    }
}
