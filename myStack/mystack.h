// Guard
#ifndef DEF_MYSTACK
#define DEF_MYSTACK

class Mystack
{
    // Méthodes
    public:
	// Push un int au sommet de la pile
    	virtual void push(int number) = 0;

	// Pop le sommet de la pile et le renvoie
    	virtual int pop(void) = 0;

	// Opérateur magique: renvoie la taille de la pile (nb d'items) modulo mod
	virtual int operator%(int mod) const = 0;

	// Purge (retire tous les éléments) de la pile
	virtual void clear() = 0;
};

#endif
