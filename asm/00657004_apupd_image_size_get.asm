; func apupd_image_size_get @ 0x00657004 size=0x2c
  657004:	27bdff48 	addiu	sp,sp,-184
  657008:	afbf00b4 	sw	ra,180(sp)
  65700c:	0c101c20 	jal	0x407080
  657010:	27a50018 	addiu	a1,sp,24
  657014:	8fa3004c 	lw	v1,76(sp)
  657018:	28420000 	slti	v0,v0,0
  65701c:	8fbf00b4 	lw	ra,180(sp)
  657020:	27bd00b8 	addiu	sp,sp,184
  657024:	0002180b 	movn	v1,zero,v0
  657028:	03e00008 	jr	ra
  65702c:	00601021 	move	v0,v1
