; func _uac_nms_event_report_test @ 0x004a1a94 size=0x28
  4a1a94:	27bdfd08 	addiu	sp,sp,-760
  4a1a98:	00003821 	move	a3,zero
  4a1a9c:	a7a60028 	sh	a2,40(sp)
  4a1aa0:	afbf02f4 	sw	ra,756(sp)
  4a1aa4:	0c1285dc 	jal	0x4a1770
  4a1aa8:	27a60018 	addiu	a2,sp,24
  4a1aac:	00001021 	move	v0,zero
  4a1ab0:	8fbf02f4 	lw	ra,756(sp)
  4a1ab4:	03e00008 	jr	ra
  4a1ab8:	27bd02f8 	addiu	sp,sp,760
