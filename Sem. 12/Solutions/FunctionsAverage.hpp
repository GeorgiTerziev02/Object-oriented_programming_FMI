template<typename F1, typename F2>
class FunctionsAverage {
private:
	const F1& first;
	const F2& second;
public:
	FunctionsAverage(const F1& first, const F2& second);
	int average(int n) const;
};

template<typename F1, typename F2>
FunctionsAverage<F1, F2>::FunctionsAverage(const F1& first, const F2& second)
	:first(first), second(second)
{ }

template<typename F1, typename F2>
int FunctionsAverage<F1, F2>::average(int n) const {
	return (first(n) + second(n)) / 2;
}
