; func _apmngr_debug_get_all_model_ids @ 0x00529fa0 size=0x28
  529fa0:	3c02007c 	lui	v0,0x7c
  529fa4:	8c840010 	lw	a0,16(a0)
  529fa8:	8c435850 	lw	v1,22608(v0)
  529fac:	00033080 	sll	a2,v1,0x2
  529fb0:	24630001 	addiu	v1,v1,1
  529fb4:	00a62821 	addu	a1,a1,a2
  529fb8:	ac435850 	sw	v1,22608(v0)
  529fbc:	00001021 	move	v0,zero
  529fc0:	03e00008 	jr	ra
  529fc4:	aca40000 	sw	a0,0(a1)
