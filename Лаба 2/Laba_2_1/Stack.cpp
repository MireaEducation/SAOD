#include "Stack.h"

Stack::Stack()
{
	this->mass = new Expression[1];
	this->size = 0;
}

void Stack::init(string exp)
{
	Expression obj(exp);
	while(!this->mass) this->mass = new Expression[1];

	if (this->mass) {
		this->size = 1;
		this->mass[0] = obj;
		
		//Если второй аргумент является мат. выражением - добавляем в стек
		if (isExpression(obj.getLastArg()))
		{
			Expression secondExp(obj.getLastArg());
			this->push(secondExp);
		}
	}
	else {
		throw new exception("Не удалось выделить память \n");
	}
}

void Stack::push(Expression elem)
{
	this->mass = this->updateSize(this->mass, this->size, this->size + 1);
	//this->mass = (Expression*)realloc(this->mass, sizeof(Expression) * this->size);
	this->size++;

	if (this->mass) {
		this->mass[size - 1] = elem;
	}
	else {
		throw new exception("Не удалось выделить память \n");
	}
}

Expression* Stack::updateSize(const Expression* exp, int size_old, int size_new)
{
		Expression* updateMass = NULL;
		updateMass = new Expression[size_new];
		if (updateMass) {
			size_t i = 0;

			for (i = 0; i < size_old; i++)
			{
				updateMass[i] = exp[i];
			}

			for (; i < size_new; i++)
			{
				updateMass[i] = Expression();
			}
		}

		return updateMass;
}

double Stack::getResultExpression()
{
	while (this->size != 0)
	{
		int last_index_oper = this->size - 1;//индекс последней операции
		int pre_last_index_oper = last_index_oper - 1;//индекс предпоследней операции

		//Если знак операции последнего элемента стека - имеет высокий приоритет
		//if(m)
	}
	return 0.0;
}
