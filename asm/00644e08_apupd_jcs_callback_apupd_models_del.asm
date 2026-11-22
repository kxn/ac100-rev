; func apupd_jcs_callback_apupd_models_del @ 0x00644e08 size=0x64
  644e08:	27bdffe0 	addiu	sp,sp,-32
  644e0c:	10800006 	beqz	a0,0x644e28
  644e10:	afbf001c 	sw	ra,28(sp)
  644e14:	10a00005 	beqz	a1,0x644e2c
  644e18:	3c020076 	lui	v0,0x76
  644e1c:	8fbf001c 	lw	ra,28(sp)
  644e20:	081912de 	j	0x644b78
  644e24:	27bd0020 	addiu	sp,sp,32
  644e28:	3c020076 	lui	v0,0x76
  644e2c:	8c428c08 	lw	v0,-29688(v0)
  644e30:	14400003 	bnez	v0,0x644e40
  644e34:	8fbf001c 	lw	ra,28(sp)
  644e38:	03e00008 	jr	ra
  644e3c:	27bd0020 	addiu	sp,sp,32
  644e40:	0c16276a 	jal	0x589da8
  644e44:	00000000 	nop
  644e48:	1040fffb 	beqz	v0,0x644e38
  644e4c:	8fbf001c 	lw	ra,28(sp)
  644e50:	3c040071 	lui	a0,0x71
  644e54:	3c050071 	lui	a1,0x71
  644e58:	24840720 	addiu	a0,a0,1824
  644e5c:	24a53ce0 	addiu	a1,a1,15584
  644e60:	240608fc 	li	a2,2300
  644e64:	08101b74 	j	0x406dd0
  644e68:	27bd0020 	addiu	sp,sp,32
