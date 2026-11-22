; func wportal_set_portal_age_time @ 0x0041b4e4 size=0x18
  41b4e4:	2402003c 	li	v0,60
  41b4e8:	3c030073 	lui	v1,0x73
  41b4ec:	70821002 	mul	v0,a0,v0
  41b4f0:	ac621240 	sw	v0,4672(v1)
  41b4f4:	03e00008 	jr	ra
  41b4f8:	00001021 	move	v0,zero
