; func cw_msg_ele_val_get @ 0x00562b2c size=0x2c
  562b2c:	27bdffe0 	addiu	sp,sp,-32
  562b30:	afbf001c 	sw	ra,28(sp)
  562b34:	0c158a80 	jal	0x562a00
  562b38:	30a5ffff 	andi	a1,a1,0xffff
  562b3c:	00401821 	move	v1,v0
  562b40:	10600002 	beqz	v1,0x562b4c
  562b44:	00001021 	move	v0,zero
  562b48:	8c620010 	lw	v0,16(v1)
  562b4c:	8fbf001c 	lw	ra,28(sp)
  562b50:	03e00008 	jr	ra
  562b54:	27bd0020 	addiu	sp,sp,32
