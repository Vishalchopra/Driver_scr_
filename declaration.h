extern int majorno, minorno;
extern unsigned int nod;

struct Qset{
	struct Qset *next;
	void **data;
};

struct DEV{
	struct Qset *qset;
	struct cdev c_dev;
};

extern dev_t dev;
extern struct DEV *sdev;
