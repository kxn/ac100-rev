; func _uac_cfg_save_task @ 0x00512be4 size=0x54
  512be4:	3c1c0025 	lui	gp,0x25
  512be8:	279ce51c 	addiu	gp,gp,-6884
  512bec:	0399e021 	addu	gp,gp,t9
  512bf0:	27bdffd8 	addiu	sp,sp,-40
  512bf4:	afbc0010 	sw	gp,16(sp)
  512bf8:	afb10020 	sw	s1,32(sp)
  512bfc:	afb0001c 	sw	s0,28(sp)
  512c00:	afbf0024 	sw	ra,36(sp)
  512c04:	8f9082ac 	lw	s0,-32084(gp)
  512c08:	8f9182b4 	lw	s1,-32076(gp)
  512c0c:	8f9986e8 	lw	t9,-31000(gp)
  512c10:	0320f809 	jalr	t9
  512c14:	240461a8 	li	a0,25000
  512c18:	8e021a70 	lw	v0,6768(s0)
  512c1c:	1040fffb 	beqz	v0,0x512c0c
  512c20:	8fbc0010 	lw	gp,16(sp)
  512c24:	263927c0 	addiu	t9,s1,10176
  512c28:	0411fee5 	bal	0x5127c0
  512c2c:	00000000 	nop
  512c30:	1000fff6 	b	0x512c0c
  512c34:	8fbc0010 	lw	gp,16(sp)
