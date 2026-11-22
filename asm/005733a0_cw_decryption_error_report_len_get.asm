; func cw_decryption_error_report_len_get @ 0x005733a0 size=0x24
  5733a0:	10800006 	beqz	a0,0x5733bc
  5733a4:	00001021 	move	v0,zero
  5733a8:	90830002 	lbu	v1,2(a0)
  5733ac:	90820001 	lbu	v0,1(a0)
  5733b0:	70621002 	mul	v0,v1,v0
  5733b4:	24420003 	addiu	v0,v0,3
  5733b8:	3042ffff 	andi	v0,v0,0xffff
  5733bc:	03e00008 	jr	ra
  5733c0:	00000000 	nop
