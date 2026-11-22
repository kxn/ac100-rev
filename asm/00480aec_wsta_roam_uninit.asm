; func wsta_roam_uninit @ 0x00480aec size=0x90
  480aec:	27bdffe0 	addiu	sp,sp,-32
  480af0:	afbf001c 	sw	ra,28(sp)
  480af4:	0c122898 	jal	0x48a260
  480af8:	afb00018 	sw	s0,24(sp)
  480afc:	10400009 	beqz	v0,0x480b24
  480b00:	3c020073 	lui	v0,0x73
  480b04:	804214d0 	lb	v0,5328(v0)
  480b08:	14400013 	bnez	v0,0x480b58
  480b0c:	2410ffff 	li	s0,-1
  480b10:	8fbf001c 	lw	ra,28(sp)
  480b14:	02001021 	move	v0,s0
  480b18:	8fb00018 	lw	s0,24(sp)
  480b1c:	03e00008 	jr	ra
  480b20:	27bd0020 	addiu	sp,sp,32
  480b24:	0c120652 	jal	0x481948
  480b28:	00008021 	move	s0,zero
  480b2c:	1040fff8 	beqz	v0,0x480b10
  480b30:	3c020073 	lui	v0,0x73
  480b34:	804214d0 	lb	v0,5328(v0)
  480b38:	1040fff5 	beqz	v0,0x480b10
  480b3c:	2410ffff 	li	s0,-1
  480b40:	3c040069 	lui	a0,0x69
  480b44:	3c050069 	lui	a1,0x69
  480b48:	24843e44 	addiu	a0,a0,15940
  480b4c:	24a53fb0 	addiu	a1,a1,16304
  480b50:	081202db 	j	0x480b6c
  480b54:	24060242 	li	a2,578
  480b58:	3c040069 	lui	a0,0x69
  480b5c:	3c050069 	lui	a1,0x69
  480b60:	24843e0c 	addiu	a0,a0,15884
  480b64:	24a53fb0 	addiu	a1,a1,16304
  480b68:	2406023d 	li	a2,573
  480b6c:	0c101b74 	jal	0x406dd0
  480b70:	00000000 	nop
  480b74:	081202c5 	j	0x480b14
  480b78:	8fbf001c 	lw	ra,28(sp)
  480b7c:	00000000 	nop
