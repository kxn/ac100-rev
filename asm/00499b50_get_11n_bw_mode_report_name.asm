; func get_11n_bw_mode_report_name @ 0x00499b50 size=0x30
  499b50:	3084ffff 	andi	a0,a0,0xffff
  499b54:	2c820008 	sltiu	v0,a0,8
  499b58:	10400006 	beqz	v0,0x499b74
  499b5c:	00042080 	sll	a0,a0,0x2
  499b60:	3c02006a 	lui	v0,0x6a
  499b64:	2442b4b4 	addiu	v0,v0,-19276
  499b68:	00822021 	addu	a0,a0,v0
  499b6c:	03e00008 	jr	ra
  499b70:	8c820000 	lw	v0,0(a0)
  499b74:	3c02006c 	lui	v0,0x6c
  499b78:	03e00008 	jr	ra
  499b7c:	2442b290 	addiu	v0,v0,-19824
