; func stats_db_auth_ok_sta_hdl_reg @ 0x00671760 size=0x1c
  671760:	10800004 	beqz	a0,0x671774
  671764:	2402ffff 	li	v0,-1
  671768:	3c02007d 	lui	v0,0x7d
  67176c:	ac44c9b8 	sw	a0,-13896(v0)
  671770:	00001021 	move	v0,zero
  671774:	03e00008 	jr	ra
  671778:	00000000 	nop
