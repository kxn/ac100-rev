; func _sensor_firm @ 0x004e30cc size=0x20
  4e30cc:	8c830014 	lw	v1,20(a0)
  4e30d0:	24020007 	li	v0,7
  4e30d4:	10620003 	beq	v1,v0,0x4e30e4
  4e30d8:	00000000 	nop
  4e30dc:	03e00008 	jr	ra
  4e30e0:	00001021 	move	v0,zero
  4e30e4:	0813412e 	j	0x4d04b8
  4e30e8:	94840010 	lhu	a0,16(a0)
