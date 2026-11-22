; func cw_priv_roaming_calculate_result_length @ 0x005bb920 size=0x60
  5bb920:	10800015 	beqz	a0,0x5bb978
  5bb924:	00001021 	move	v0,zero
  5bb928:	8c830008 	lw	v1,8(a0)
  5bb92c:	24020006 	li	v0,6
  5bb930:	8c870004 	lw	a3,4(a0)
  5bb934:	2406001c 	li	a2,28
  5bb938:	2405000a 	li	a1,10
  5bb93c:	70621002 	mul	v0,v1,v0
  5bb940:	00001821 	move	v1,zero
  5bb944:	2442000a 	addiu	v0,v0,10
  5bb948:	1067000b 	beq	v1,a3,0x5bb978
  5bb94c:	3042ffff 	andi	v0,v0,0xffff
  5bb950:	70664002 	mul	t0,v1,a2
  5bb954:	8c890010 	lw	t1,16(a0)
  5bb958:	24630001 	addiu	v1,v1,1
  5bb95c:	01284021 	addu	t0,t1,t0
  5bb960:	91080016 	lbu	t0,22(t0)
  5bb964:	71054002 	mul	t0,t0,a1
  5bb968:	25080017 	addiu	t0,t0,23
  5bb96c:	00481021 	addu	v0,v0,t0
  5bb970:	1467fff7 	bne	v1,a3,0x5bb950
  5bb974:	3042ffff 	andi	v0,v0,0xffff
  5bb978:	03e00008 	jr	ra
  5bb97c:	00000000 	nop
