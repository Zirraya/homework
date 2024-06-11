using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Hero : Entity
{
	[SerializeField] private float speed = 3f; // �������� ��������
	[SerializeField] private int health; // ���-�� ������
	[SerializeField] private float jumpForce = 15f; //���� ������
	private bool isGrounded = false;

	[SerializeField] private Image[] hearts;
	[SerializeField] private Sprite alivaheart;
	[SerializeField] private Sprite deadheart;


	private Rigidbody2D rb;
	private Animator anim;
	private SpriteRenderer sprite;
	private Vector3 moveVector;

	public static Hero Instance { get; set; } // ��� �� �� ��������� ��������� Hero ������ ���

	private States State // ���� ���������
	{
		get { return (States)anim.GetInteger("state"); } // �������� ������� �� ������ ���������
		set { anim.SetInteger("state", (int)value); } // ������������ ������� �� ������
	}

	private void Awake()
	{
		lives = 3;
		health = lives;
		Instance = this;

		rb = GetComponent<Rigidbody2D>();
		anim = GetComponent<Animator>();
		sprite = GetComponentInChildren<SpriteRenderer>();
		Instance = this; // ��� �� �� ���� ������ ��� ��������������� � �������
		
	}
	private void Update() // ����� ��� ������ ������ � ���� �� �������
	{
		if (isGrounded ) State = States.Idle; // ��� �������� �����

		if ( Input.GetButton("Horizontal"))
			Run();

		if ( isGrounded && Input.GetButtonDown("Jump")) // ��������� isgrounded ������ ������ �� ����� �����������
			Jump();

		if (health > lives)  // ����������� ��������
			health = lives;

		for(int i = 0; i < hearts.Length; i++) // ���� ��� ����������� ��������
        {
			if (i < health)
				hearts[i].sprite = alivaheart;
			else
				hearts[i].sprite = deadheart;
			if (i < lives)
				hearts[i].enabled = true;
			else
				hearts[i].enabled = false;
        }
	}
	


	private void FixedUpdate() // ��� �� ������ ������� � ������������ :)
	{
		CheckGround();
	}



	private void Run() // ����� ��� ����
	{
		if (isGrounded) State = States.Run; // ��� �������� ����
		var movement = Input.GetAxis("Horizontal");
		transform.position += new Vector3(movement, 0, 0) * Time.deltaTime * speed;
		if (!Mathf.Approximately(0, movement))
			transform.rotation = movement < 0 ? Quaternion.Euler(0, 180, 0) : Quaternion.identity;

        

		
	}

	
	private void Jump() // ����� ��� ������
	{
		rb.AddForce(transform.up * jumpForce, ForceMode2D.Impulse);
	}

	
    private void CheckGround() // ����� ��� �������� ����������� ��� ������
	{
		Collider2D[] collider = Physics2D.OverlapCircleAll(transform.position, 0.3f);
		isGrounded = collider.Length > 1;

		if (!isGrounded) State = States.Jump; // ��� �������� ������
	}

    public override void GetDamage()
    {
		health -= 1;
        if (health == 0)
        {
			foreach (var h in hearts)
				h.sprite = deadheart;
			Die();
        }
    }



	
}


public enum States // ���� ���������
{
	Idle,
	Run,
	Jump
	
	
	
}

