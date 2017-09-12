#include "element.h"
C_element::C_element() {
	C_grandparents grandparent;
	C_parent parent;
	C_partner partner;
	C_children children;
	C_sibling sibling;
	C_grandchildren grandchildren;
	C_order order;
	int i;
	for (i = 0; i < 2; i++)
		V_parent.m_push_back(parent);
	for (i = 0; i < 4; i++)
		V_grandparents.m_push_back(grandparent);
	V_partner.m_push_back(partner);
	V_sibling.m_push_back(sibling);
	V_children.m_push_back(children);
	V_grandchildren.m_push_back(grandchildren);
	V_order.m_push_back(order);
}
C_element::C_element(C_human V_human, N_vektor<C_goverment_relation> V_gover) {
	//zrobic analize relacji i na niej podstawie zapelnic id w relacjach i bedzie to poprawne wczytywanie danych
	int i,j,t;
	Human = V_human;
	C_id ID(Human.m_set_id());
	for (i = 0; i < V_gover.m_size(); i++) //powinno dzialac poprawnie!!
	{
		N_striing data = V_gover[i].m_set_contens(),temp;
		for (j = 0; j < data.m_size(); j++)
		{
			if (data[j] == '>')
				break;
			else if (data[j] == 'r')
			{
				switch (data[j + 1])
				{
				/*case t_id_personaly:
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					for (t = 0; t < V_human.m_size(); t++)
					{
						if (V_human[t].m_set_id() == id)
						{
							Human = V_human[t];
							break;
						}
					}
					break;
				}*/
				case '4':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_grandchildren grand(id);

					V_grandchildren.m_push_back(grand);
					break;
				}
				case '1':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_children grand(ID);
					grand.m_get_id(id);
					V_children.m_push_back(grand);
					break;
				}
				case '2':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_sibling grand(ID);
					grand.m_get_id(id);
					V_sibling.m_push_back(grand);
					break;
				}
				case '5':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_partner grand(ID);
					grand.m_get_id(id);
					V_partner.m_push_back(grand);
					break;
				}
				case '0':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_parent grand(ID);
					grand.m_get_id(id);
					V_parent.m_push_back(grand);
					break;
				}
				case '3':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_grandparents grand(ID);
					grand.m_get_id(id);
					V_grandparents.m_push_back(grand);
					break;
				}
				case '6':
				{
					temp.m_clear();
					t = 1;
					while (true)
					{
						if (data[j + 1 + t] == 'r' || data[j + 1 + t] == '>') {
							j += t;
							break;
						}
						temp += data[j + 1 + t];
						t++;
					}
					C_id id(temp.m_atoi(0, temp.m_size() - 1));
					C_order grand(ID);
					grand.m_get_id(id);
					V_order.m_push_back(grand);
					break;
				}
				}
			}
		}
	}
}
C_element::C_element(const C_element &element) { if (this != &element) *this = element; }
C_element& C_element::operator=(const C_element &element) {
	if (this == &element) return *this;
	if (*this == element) return *this;
	Human = element.Human;
	V_children = element.V_children;
	V_parent = element.V_parent;
	V_sibling = element.V_sibling;
	V_grandchildren = element.V_grandchildren;
	V_grandparents = element.V_grandparents;
	V_partner = element.V_partner;
	V_order = element.V_order;
	return *this;
}
bool C_element::operator==(const C_element &element) {
	if (V_children == element.V_children&&V_parent==element.V_parent&&
		V_sibling==element.V_sibling&&V_grandchildren==element.V_grandchildren&&
		V_grandparents == element.V_grandparents&&V_partner==element.V_partner&&
		V_order == element.V_order&&Human == element.Human) return true;
	return false;
}
bool C_element::operator!=(const C_element &element) {
	if (V_children != element.V_children||
		V_parent != element.V_parent||
		V_sibling != element.V_sibling||
		V_grandchildren != element.V_grandchildren||
		V_grandparents != element.V_grandparents||
		V_partner != element.V_partner||
		V_order != element.V_order||
		Human!=element.Human) return true;
	return false;
}
C_element::~C_element() {}
C_element::C_element(const C_human& human) { Human = human; }
void C_element::m_get_children(C_children &children) { V_children.m_push_back(children); }
void C_element::m_get_parent(C_parent &parent) { V_parent.m_push_back(parent); }
void C_element::m_get_sibling(C_sibling &sibling) { V_sibling.m_push_back(sibling); }
void C_element::m_get_grandchildren(C_grandchildren &grandchildren) {V_grandchildren.m_push_back(grandchildren); }
void C_element::m_get_grandparents(C_grandparents &grandparents) { V_grandparents.m_push_back(grandparents); }
void C_element::m_get_partner(C_partner &partner) { V_partner.m_push_back(partner); }
void C_element::m_get_order(C_order &order) { V_order.m_push_back(order); }
void C_element::m_update_children(int value, C_children &children) {
	V_children.m_erase(value); V_children.m_insert(value, children);
}
void C_element::m_update_parent(int value, C_parent &parent) {
	V_parent.m_erase(value); V_parent.m_insert(value, parent);
}
void C_element::m_update_sibling(int value, C_sibling &sibling) {
	V_sibling.m_erase(value); V_sibling.m_insert(value, sibling); 
}
void C_element::m_update_grandchildren(int value, C_grandchildren &grandchildren) {
	V_grandchildren.m_erase(value); V_grandchildren.m_insert(value, grandchildren);
}
void C_element::m_update_grandparents(int value, C_grandparents &parents){
	V_grandparents.m_erase(value); V_grandparents.m_insert(value, parents);
}
void C_element::m_update_partner(int value, C_partner &partner) {
	V_partner.m_erase(value); V_partner.m_insert(value, partner);
}
void C_element::m_update_order(int value, C_order &order) {
	V_order.m_erase(value); V_order.m_insert(value, order);
}
void C_element::m_update_human(const C_human &human) { Human = human; }
C_human C_element::m_set_Human() { return Human; }
C_children C_element::m_set_children() { return V_children[0]; }
C_parent C_element::m_set_parent() { return V_parent[0]; }
C_sibling C_element::m_set_sibling() { return V_sibling[0]; }
C_partner C_element::m_set_partner() { return V_partner[0]; }
C_grandchildren C_element::m_set_grandchildren() { return V_grandchildren[0]; }
C_grandparents C_element::m_set_grandparents() { return V_grandparents[0]; }
C_order C_element::m_set_order() { return V_order[0]; }
C_children C_element::m_set_children(int value) { return V_children[value]; }
C_parent C_element::m_set_parent(int value) { return V_parent[value]; }
C_sibling C_element::m_set_sibling(int value) { return V_sibling[value]; }
C_grandchildren C_element::m_set_grandchildren(int value) { return V_grandchildren[value]; }
C_grandparents C_element::m_set_grandparents(int value) { return V_grandparents[value]; }
C_partner C_element::m_set_partner(int value) { return V_partner[value]; }
C_order C_element::m_set_order(int value) { return V_order[value]; }
C_element& C_element::m_clean() { C_element E; return E; }
void C_element::m_clean_children() { V_children.m_close(); }
void C_element::m_clean_parent() { V_parent.m_close(); }
void C_element::m_clean_sibling() { V_sibling.m_close(); }
void C_element::m_clean_grandparents() { V_grandparents.m_close(); }
void C_element::m_clean_grandchildren() { V_grandchildren.m_close(); }
void C_element::m_clean_partner() { V_partner.m_close(); }
void C_element::m_clean_order() { V_order.m_close(); }
void C_element::m_delete_children() { V_children.m_pop_front(); }
void C_element::m_delete_parent() { V_parent.m_pop_front(); }
void C_element::m_delete_sibling() { V_sibling.m_pop_front(); }
void C_element::m_delete_partner() { V_partner.m_pop_front(); }
void C_element::m_delete_order() { V_order.m_pop_front(); }
void C_element::m_delete_children(int value) { V_children.m_erase(value); }
void C_element::m_delete_parent(int value) { V_parent.m_erase(value); }
void C_element::m_delete_sibling(int value) { V_sibling.m_erase(value); }
void C_element::m_delete_grandchildren(int value) { V_grandchildren.m_erase(value); }
void C_element::m_delete_grandparents(int value) { V_grandparents.m_erase(value); }
void C_element::m_delete_partner(int value) { V_partner.m_erase(value); }
void C_element::m_delete_order(int value) { V_order.m_erase(value); }
N_vektor<C_grandparents> C_element::m_set_v_grandparents() { return V_grandparents; }
N_vektor<C_grandchildren> C_element::m_set_v_grandchildren() { return V_grandchildren; }
N_vektor<C_parent> C_element::m_set_v_parent() { return V_parent; }
N_vektor<C_children> C_element::m_set_v_children() { return V_children; }
N_vektor <C_partner> C_element::m_set_v_partner() { return V_partner; }
N_vektor<C_sibling> C_element::m_set_v_sibling() { return V_sibling; }
N_vektor <C_order> C_element::m_set_v_order() { return V_order; }
