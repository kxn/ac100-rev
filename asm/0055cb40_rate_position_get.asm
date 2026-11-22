; func rate_position_get @ 0x0055cb40 size=0x38
  55cb40:	3c03006d 	lui	v1,0x6d
  55cb44:	00001021 	move	v0,zero
  55cb48:	24631670 	addiu	v1,v1,5744
  55cb4c:	2405000c 	li	a1,12
  55cb50:	24630004 	addiu	v1,v1,4
  55cb54:	8c66fffc 	lw	a2,-4(v1)
  55cb58:	10860005 	beq	a0,a2,0x55cb70
  55cb5c:	00000000 	nop
  55cb60:	24420001 	addiu	v0,v0,1
  55cb64:	5445fffb 	bnel	v0,a1,0x55cb54
  55cb68:	24630004 	addiu	v1,v1,4
  55cb6c:	2402ffff 	li	v0,-1
  55cb70:	03e00008 	jr	ra
  55cb74:	00000000 	nop
