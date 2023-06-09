// Actividad Integradora 3.4 - Archivo de Prueba en C# para el Resaltador de Sintaxis
// Fernanda Cantú A01782232 & Alina Rosas A01252720

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimateZombie : MonoBehaviour
{
 
 public float  speed;
 public float checkRadius;
 public float attackRadius;

 public bool shouldRotate;

 public LayerMask WhatIsPlayer;

 private Transform target; 
 private Rigidbody2D rb;
 private Animator anim;
 private Vector2 movement;
public Vector3 dir;

private bool isInChaseRange;
private bool isInAttackRange;

private void start()
{
    rb = GetComponent<Rigidbody2D>();
    anim = GetComponent<Animator>();
    target = GameObject.Find('Player').transform;

}
private void update()
{
    anim.SetBool('isRunning', isInChaseRange);

    isInChaseRange = Physics2D.OverlapCircle(transform.position, checkRadius, WhatIsPlayer);
    isInAttackRange = Physics2D.OverlapCircle(transform.position, attackRadius, WhatIsPlayer);

    dir = target.position - transform.position;
    float angle = Mathf.Atan2(dir.y, dir.x) * Mathf.Rad2Deg;
    dir.Normalize();
    movement = dir;
    if(shouldRotate)
    {
        anim.SetFloat('X', dir.x);
        anim.SetFloat('Y', dir.y);
    }
}

private void FixUpdate()
{
    if(isInChaseRange && !isInAttackRange)
    {
        MoveCharacter(movement);
    }
    if(isInAttackRange)
    {
        rb.velocity = Vector2.zero;
    }

}
    private void MoveCharacter(Vector2 dir)
    {
        rb.MovePosition((Vector2)transform.position + (dir * speed * Time.deltaTime));
    }
}
