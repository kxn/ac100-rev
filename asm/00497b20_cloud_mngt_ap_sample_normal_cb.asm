; func cloud_mngt_ap_sample_normal_cb @ 0x00497b20 size=0x60
  497b20:	27bdffe0 	addiu	sp,sp,-32
  497b24:	2c820004 	sltiu	v0,a0,4
  497b28:	afb00018 	sw	s0,24(sp)
  497b2c:	2410ffff 	li	s0,-1
  497b30:	1040000a 	beqz	v0,0x497b5c
  497b34:	afbf001c 	sw	ra,28(sp)
  497b38:	3c020076 	lui	v0,0x76
  497b3c:	8c4277dc 	lw	v0,30684(v0)
  497b40:	10400006 	beqz	v0,0x497b5c
  497b44:	00008021 	move	s0,zero
  497b48:	3c020076 	lui	v0,0x76
  497b4c:	8c4277d8 	lw	v0,30680(v0)
  497b50:	00821025 	or	v0,a0,v0
  497b54:	14400006 	bnez	v0,0x497b70
  497b58:	00000000 	nop
  497b5c:	8fbf001c 	lw	ra,28(sp)
  497b60:	02001021 	move	v0,s0
  497b64:	8fb00018 	lw	s0,24(sp)
  497b68:	03e00008 	jr	ra
  497b6c:	27bd0020 	addiu	sp,sp,32
  497b70:	0c123b87 	jal	0x48ee1c
  497b74:	2484000c 	addiu	a0,a0,12
  497b78:	08125ed8 	j	0x497b60
  497b7c:	8fbf001c 	lw	ra,28(sp)
