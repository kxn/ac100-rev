; func stats_db_fail_sta_hdl_reg @ 0x00671744 size=0x1c
  671744:	10800004 	beqz	a0,0x671758
  671748:	2402ffff 	li	v0,-1
  67174c:	3c02007d 	lui	v0,0x7d
  671750:	ac44c9bc 	sw	a0,-13892(v0)
  671754:	00001021 	move	v0,zero
  671758:	03e00008 	jr	ra
  67175c:	00000000 	nop
