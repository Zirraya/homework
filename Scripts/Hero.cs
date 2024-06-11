using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hero : MonoBehaviour
{
	[SerializeField] private float speed = 3f; // скорость движени€
	[SerializeField] private int lives = 5; // кол-во жизней
	[SerializeField] private float jumpForce = 15f; //сила прыжка
	private bool isGrounded = false;


	private Rigidbody2D rb;
	private Animator anim;
	private SpriteRenderer sprite;

	public static Hero Instance { get; set; } // что бы не создавать экземпл€р Hero каждый раз

	private States State // пол€ состо€ний
	{
		get { return (States)anim.GetInteger("state"); } // получаем команды из списка аниматора
		set { anim.SetInteger("state", (int)value); } // контролируем команды из списка
	}

	private void Awake()
{
		rb = GetComponent<Rigidbody2D>();
		anim = GetComponent<Animator>();
		sprite = GetComponentInChildren<SpriteRenderer>();
		Instance = this; // что бы не было ошибки при соприкосновение с игроком
	}
	private void Update() // метод дл€ работы пражка и бега по кнопкам
	{
		if (isGrounded) State = States.Idle; // дл€ анимации поко€

		if (Input.GetButton("Horizontal"))
			Run();

		if (isGrounded && Input.GetButtonDown("Jump")) // благодор€ isgrounded прыжок больше не будет бесконечным
			Jump();
	}
	


	private void FixedUpdate() // что бы небыло проблем с поверхностью :)
	{
		CheckGround();
	}



	private void Run() // метод дл€ бега
	{
		if (isGrounded) State = States.Run; // дл€ анимации бега

		Vector3 dir = transform.right * Input.GetAxis("Horizontal");
		transform.position = Vector3.MoveTowards(transform.position, transform.position + dir, speed * Time.deltaTime);
		sprite.flipX = dir.x < 0.0f; // что бы персонаж поворачиволс€

		
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

    public void GetDamage()
    {
		lives -= 1;
		Debug.Log(lives);
    }

	 

}
public enum States // пол€ состо€ний
{
	Idle,
	Run,
	Jump
	
	
}

