; func cw_msg_ele_priv_val_get @ 0x00582c9c size=0x2c
  582c9c:	27bdffe0 	addiu	sp,sp,-32
  582ca0:	afbf001c 	sw	ra,28(sp)
  582ca4:	0c160b12 	jal	0x582c48
  582ca8:	30a5ffff 	andi	a1,a1,0xffff
  582cac:	00401821 	move	v1,v0
  582cb0:	10600002 	beqz	v1,0x582cbc
  582cb4:	00001021 	move	v0,zero
  582cb8:	8c620010 	lw	v0,16(v1)
  582cbc:	8fbf001c 	lw	ra,28(sp)
  582cc0:	03e00008 	jr	ra
  582cc4:	27bd0020 	addiu	sp,sp,32
