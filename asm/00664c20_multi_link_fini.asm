; func multi_link_fini @ 0x00664c20 size=0x3c
  664c20:	3c02007d 	lui	v0,0x7d
  664c24:	27bdffe0 	addiu	sp,sp,-32
  664c28:	8c44c814 	lw	a0,-14316(v0)
  664c2c:	10800003 	beqz	a0,0x664c3c
  664c30:	afbf001c 	sw	ra,28(sp)
  664c34:	0c101f7c 	jal	0x407df0
  664c38:	00000000 	nop
  664c3c:	3c02007d 	lui	v0,0x7d
  664c40:	8c44c818 	lw	a0,-14312(v0)
  664c44:	10800003 	beqz	a0,0x664c54
  664c48:	8fbf001c 	lw	ra,28(sp)
  664c4c:	08101f7c 	j	0x407df0
  664c50:	27bd0020 	addiu	sp,sp,32
  664c54:	03e00008 	jr	ra
  664c58:	27bd0020 	addiu	sp,sp,32
