; func cw_priv_roaming_trigger_length @ 0x005bcfc0 size=0x4c
  5bcfc0:	10800010 	beqz	a0,0x5bd004
  5bcfc4:	00001021 	move	v0,zero
  5bcfc8:	8c860004 	lw	a2,4(a0)
  5bcfcc:	00001821 	move	v1,zero
  5bcfd0:	24020007 	li	v0,7
  5bcfd4:	1066000b 	beq	v1,a2,0x5bd004
  5bcfd8:	24050009 	li	a1,9
  5bcfdc:	8c880008 	lw	t0,8(a0)
  5bcfe0:	00033900 	sll	a3,v1,0x4
  5bcfe4:	24630001 	addiu	v1,v1,1
  5bcfe8:	01073821 	addu	a3,t0,a3
  5bcfec:	90e70009 	lbu	a3,9(a3)
  5bcff0:	70e53802 	mul	a3,a3,a1
  5bcff4:	24e7000a 	addiu	a3,a3,10
  5bcff8:	00471021 	addu	v0,v0,a3
  5bcffc:	1466fff8 	bne	v1,a2,0x5bcfe0
  5bd000:	3042ffff 	andi	v0,v0,0xffff
  5bd004:	03e00008 	jr	ra
  5bd008:	00000000 	nop
