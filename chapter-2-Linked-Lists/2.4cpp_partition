/**
 *  Cracking the coding interview edition 6
 *  Problem 2.4 Partition:
 *  Write code to partition linked list around a value x, such that
 *  nodes less than x come before all the nodes greater than or equal to x.
 *  If x is in the list, the values of x only need to be after the elements less
 *  than x.
 *  Example
 *  3-->5-->8-->5-->10-->2-->1 (x = 5)
 *  3-->1-->2-->10-->5-->5-->8
 *
 *  Approach:
 *  Use quicksort partition approach by swapping the values of the nodes
 *  in-place. Complexity is O(n).
 */
 typedef struct node {
	int val;
	struct node *next;
} node;

void swap(node *n1, node *n2)
{
	int tmp;
	if (n1 == NULL || n2 == NULL)
		return;
	tmp = n1->val;
	n1->val = n2->val;
	n2->val = tmp;
}

bool findnSwap(node *head, int p)
{
	node *tmpHead = head;

	while (head) {
		if (head->val == p) {
			swap(head, tmpHead);
			return true;
		}
		head = head->next;
	}
	return false;
}

void partitionList(node *head, int p)
{
	node *tmpHead = head;
	node *prevP = head;
	if (head == NULL)
		return;

	if (!findnSwap(head, p))
		return;

	node *partition = head->next;
	head = head->next;

	while (head) {
		if (p > head->val) {
			swap(head, partition);
			prevP = partition;
			partition = partition->next;
		}
		head = head->next;
	}
	swap(tmpHead, prevP);
}
