using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Hero : Entity
{
	[SerializeField] private float speed = 3f; // скорость движени€
	[SerializeField] private int health; // кол-во жизней
	[SerializeField] private float jumpForce = 15f; //сила прыжка
	private bool isGrounded = false;

	[SerializeField] private Image[] hearts;
	[SerializeField] private Sprite alivaheart;
	[SerializeField] private Sprite deadheart;


	private Rigidbody2D rb;
	private Animator anim;
	private SpriteRenderer sprite;
	private Vector3 moveVector;

	public static Hero Instance { get; set; } // что бы не создавать экземпл€р Hero каждый раз

	private States State // пол€ состо€ний
	{
		get { return (States)anim.GetInteger("state"); } // получаем команды из списка аниматора
		set { anim.SetInteger("state", (int)value); } // контролируем команды из списка
	}

	private void Awake()
	{
		lives = 3;
		health = lives;
		Instance = this;

		rb = GetComponent<Rigidbody2D>();
		anim = GetComponent<Animator>();
		sprite = GetComponentInChildren<SpriteRenderer>();
		Instance = this; // что бы не было ошибки при соприкосновение с игроком
		
	}
	private void Update() // метод дл€ работы пражка и бега по кнопкам
	{
		if (isGrounded ) State = States.Idle; // дл€ анимации поко€

		if ( Input.GetButton("Horizontal"))
			Run();

		if ( isGrounded && Input.GetButtonDown("Jump")) // благодор€ isgrounded прыжок больше не будет бесконечным
			Jump();

		if (health > lives)  // ограничение здоровь€
			health = lives;

		for(int i = 0; i < hearts.Length; i++) // цикл дл€ отаброжени€ здоровь€
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
	


	private void FixedUpdate() // что бы небыло проблем с поверхностью :)
	{
		CheckGround();
	}



	private void Run() // метод дл€ бега
	{
		if (isGrounded) State = States.Run; // дл€ анимации бега
		var movement = Input.GetAxis("Horizontal");
		transform.position += new Vector3(movement, 0, 0) * Time.deltaTime * speed;
		if (!Mathf.Approximately(0, movement))
			transform.rotation = movement < 0 ? Quaternion.Euler(0, 180, 0) : Quaternion.identity;

        

		
	}

	
	private void Jump() // метод дл€ прыжка
	{
		rb.AddForce(transform.up * jumpForce, ForceMode2D.Impulse);
	}

	
    private void CheckGround() // метод дл€ проверки поверхности под ногами
	{
		Collider2D[] collider = Physics2D.OverlapCircleAll(transform.position, 0.3f);
		isGrounded = collider.Length > 1;

		if (!isGrounded) State = States.Jump; // дл€ анимации прыжка
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


public enum States // пол€ состо€ний
{
	Idle,
	Run,
	Jump
	
	
	
}

