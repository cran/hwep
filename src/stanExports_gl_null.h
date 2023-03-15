// Generated by rstantools.  Do not edit by hand.

/*
    hwep is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    hwep is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with hwep.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#ifndef USE_STANC3
#define USE_STANC3
#endif
#include <rstan/rstaninc.hpp>
// Code generated by %%NAME%% %%VERSION%%
#include <stan/model/model_header.hpp>
namespace model_gl_null_namespace {
inline void validate_positive_index(const char* var_name, const char* expr,
                                    int val) {
  if (val < 1) {
    std::stringstream msg;
    msg << "Found dimension size less than one in simplex declaration"
        << "; variable=" << var_name << "; dimension size expression=" << expr
        << "; expression value=" << val;
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}
inline void validate_unit_vector_index(const char* var_name, const char* expr,
                                       int val) {
  if (val <= 1) {
    std::stringstream msg;
    if (val == 1) {
      msg << "Found dimension size one in unit vector declaration."
          << " One-dimensional unit vector is discrete"
          << " but the target distribution must be continuous."
          << " variable=" << var_name << "; dimension size expression=" << expr;
    } else {
      msg << "Found dimension size less than one in unit vector declaration"
          << "; variable=" << var_name << "; dimension size expression=" << expr
          << "; expression value=" << val;
    }
    std::string msg_str(msg.str());
    throw std::invalid_argument(msg_str.c_str());
  }
}
using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using std::pow;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::model_base_crtp;
using stan::model::rvalue;
using stan::model::cons_list;
using stan::model::index_uni;
using stan::model::index_max;
using stan::model::index_min;
using stan::model::index_min_max;
using stan::model::index_multi;
using stan::model::index_omni;
using stan::model::nil_index_list;
using namespace stan::math;
using stan::math::pow; 
stan::math::profile_map profiles__;
static int current_statement__= 0;
static const std::vector<string> locations_array__ = {" (found before start of program)",
                                                      " (in 'gl_null', line 9, column 2 to column 19)",
                                                      " (in 'gl_null', line 13, column 2 to column 17)",
                                                      " (in 'gl_null', line 15, column 4 to column 36)",
                                                      " (in 'gl_null', line 16, column 4 to column 32)",
                                                      " (in 'gl_null', line 17, column 4 to column 15)",
                                                      " (in 'gl_null', line 19, column 6 to column 34)",
                                                      " (in 'gl_null', line 18, column 23 to line 20, column 5)",
                                                      " (in 'gl_null', line 18, column 4 to line 20, column 5)",
                                                      " (in 'gl_null', line 14, column 21 to line 21, column 3)",
                                                      " (in 'gl_null', line 14, column 2 to line 21, column 3)",
                                                      " (in 'gl_null', line 24, column 2 to column 38)",
                                                      " (in 'gl_null', line 26, column 11 to column 14)",
                                                      " (in 'gl_null', line 26, column 4 to column 19)",
                                                      " (in 'gl_null', line 28, column 6 to column 35)",
                                                      " (in 'gl_null', line 27, column 23 to line 29, column 5)",
                                                      " (in 'gl_null', line 27, column 4 to line 29, column 5)",
                                                      " (in 'gl_null', line 30, column 4 to column 30)",
                                                      " (in 'gl_null', line 25, column 17 to line 31, column 3)",
                                                      " (in 'gl_null', line 25, column 2 to line 31, column 3)",
                                                      " (in 'gl_null', line 2, column 2 to column 17)",
                                                      " (in 'gl_null', line 3, column 2 to column 17)",
                                                      " (in 'gl_null', line 4, column 2 to column 21)",
                                                      " (in 'gl_null', line 5, column 9 to column 10)",
                                                      " (in 'gl_null', line 5, column 12 to column 15)",
                                                      " (in 'gl_null', line 5, column 2 to column 20)",
                                                      " (in 'gl_null', line 6, column 9 to column 14)",
                                                      " (in 'gl_null', line 6, column 2 to column 22)",
                                                      " (in 'gl_null', line 9, column 10 to column 15)",
                                                      " (in 'gl_null', line 13, column 10 to column 13)"};
#include <stan_meta_header.hpp>
class model_gl_null final : public model_base_crtp<model_gl_null> {
private:
  int N;
  int K;
  int khalf;
  Eigen::Matrix<double, -1, -1> gl;
  Eigen::Matrix<double, -1, 1> alpha;
  int q_1dim__;
 
public:
  ~model_gl_null() { }
  
  inline std::string model_name() const final { return "model_gl_null"; }
  inline std::vector<std::string> model_compile_info() const noexcept {
    return std::vector<std::string>{"stanc_version = %%NAME%%3 %%VERSION%%", "stancflags = "};
  }
  
  
  model_gl_null(stan::io::var_context& context__,
                unsigned int random_seed__ = 0,
                std::ostream* pstream__ = nullptr) : model_base_crtp(0) {
    using local_scalar_t__ = double ;
    boost::ecuyer1988 base_rng__ = 
        stan::services::util::create_rng(random_seed__, 0);
    (void) base_rng__;  // suppress unused var warning
    static const char* function__ = "model_gl_null_namespace::model_gl_null";
    (void) function__;  // suppress unused var warning
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      current_statement__ = 20;
      context__.validate_dims("data initialization","N","int",
          context__.to_vec());
      N = std::numeric_limits<int>::min();
      
      current_statement__ = 20;
      N = context__.vals_i("N")[(1 - 1)];
      current_statement__ = 20;
      current_statement__ = 20;
      check_greater_or_equal(function__, "N", N, 0);
      current_statement__ = 21;
      context__.validate_dims("data initialization","K","int",
          context__.to_vec());
      K = std::numeric_limits<int>::min();
      
      current_statement__ = 21;
      K = context__.vals_i("K")[(1 - 1)];
      current_statement__ = 21;
      current_statement__ = 21;
      check_greater_or_equal(function__, "K", K, 2);
      current_statement__ = 22;
      context__.validate_dims("data initialization","khalf","int",
          context__.to_vec());
      khalf = std::numeric_limits<int>::min();
      
      current_statement__ = 22;
      khalf = context__.vals_i("khalf")[(1 - 1)];
      current_statement__ = 22;
      current_statement__ = 22;
      check_greater_or_equal(function__, "khalf", khalf, 2);
      current_statement__ = 23;
      validate_non_negative_index("gl", "N", N);
      current_statement__ = 24;
      validate_non_negative_index("gl", "K + 1", (K + 1));
      current_statement__ = 25;
      context__.validate_dims("data initialization","gl","double",
          context__.to_vec(N, (K + 1)));
      gl = Eigen::Matrix<double, -1, -1>(N, (K + 1));
      stan::math::fill(gl, std::numeric_limits<double>::quiet_NaN());
      
      {
        std::vector<local_scalar_t__> gl_flat__;
        current_statement__ = 25;
        assign(gl_flat__, nil_index_list(), context__.vals_r("gl"),
          "assigning variable gl_flat__");
        current_statement__ = 25;
        pos__ = 1;
        current_statement__ = 25;
        for (int sym1__ = 1; sym1__ <= (K + 1); ++sym1__) {
          current_statement__ = 25;
          for (int sym2__ = 1; sym2__ <= N; ++sym2__) {
            current_statement__ = 25;
            assign(gl,
              cons_list(index_uni(sym2__),
                cons_list(index_uni(sym1__), nil_index_list())),
              gl_flat__[(pos__ - 1)], "assigning variable gl");
            current_statement__ = 25;
            pos__ = (pos__ + 1);}}
      }
      current_statement__ = 26;
      validate_non_negative_index("alpha", "khalf", khalf);
      current_statement__ = 27;
      context__.validate_dims("data initialization","alpha","double",
          context__.to_vec(khalf));
      alpha = Eigen::Matrix<double, -1, 1>(khalf);
      stan::math::fill(alpha, std::numeric_limits<double>::quiet_NaN());
      
      {
        std::vector<local_scalar_t__> alpha_flat__;
        current_statement__ = 27;
        assign(alpha_flat__, nil_index_list(), context__.vals_r("alpha"),
          "assigning variable alpha_flat__");
        current_statement__ = 27;
        pos__ = 1;
        current_statement__ = 27;
        for (int sym1__ = 1; sym1__ <= khalf; ++sym1__) {
          current_statement__ = 27;
          assign(alpha, cons_list(index_uni(sym1__), nil_index_list()),
            alpha_flat__[(pos__ - 1)], "assigning variable alpha");
          current_statement__ = 27;
          pos__ = (pos__ + 1);}
      }
      current_statement__ = 28;
      validate_positive_index("p", "khalf", khalf);
      current_statement__ = 29;
      q_1dim__ = std::numeric_limits<int>::min();
      
      current_statement__ = 29;
      q_1dim__ = (K + 1);
      current_statement__ = 29;
      validate_non_negative_index("q", "K + 1", q_1dim__);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    num_params_r__ = 0U;
    
    try {
      num_params_r__ += (khalf - 1);
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
  }
  template <bool propto__, bool jacobian__, typename VecR, typename VecI, stan::require_vector_like_t<VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline stan::scalar_type_t<VecR> log_prob_impl(VecR& params_r__,
                                                 VecI& params_i__,
                                                 std::ostream* pstream__ = nullptr) const {
    using T__ = stan::scalar_type_t<VecR>;
    using local_scalar_t__ = T__;
    T__ lp__(0.0);
    stan::math::accumulator<T__> lp_accum__;
    static const char* function__ = "model_gl_null_namespace::log_prob";
(void) function__;  // suppress unused var warning
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      Eigen::Matrix<local_scalar_t__, -1, 1> p;
      p = Eigen::Matrix<local_scalar_t__, -1, 1>(khalf);
      stan::math::fill(p, DUMMY_VAR__);
      
      Eigen::Matrix<local_scalar_t__, -1, 1> p_in__;
      p_in__ = Eigen::Matrix<local_scalar_t__, -1, 1>((khalf - 1));
      stan::math::fill(p_in__, DUMMY_VAR__);
      
      current_statement__ = 1;
      p_in__ = in__.vector((khalf - 1));
      current_statement__ = 1;
      if (jacobian__) {
        current_statement__ = 1;
        assign(p, nil_index_list(),
          stan::math::simplex_constrain(p_in__, lp__), "assigning variable p");
      } else {
        current_statement__ = 1;
        assign(p, nil_index_list(), stan::math::simplex_constrain(p_in__),
          "assigning variable p");
      }
      Eigen::Matrix<local_scalar_t__, -1, 1> q;
      q = Eigen::Matrix<local_scalar_t__, -1, 1>(q_1dim__);
      stan::math::fill(q, DUMMY_VAR__);
      
      current_statement__ = 10;
      for (int k = 1; k <= (K + 1); ++k) {
        int iup;
        iup = std::numeric_limits<int>::min();
        
        current_statement__ = 3;
        iup = std::min((k - 1), (khalf - 1));
        int ilo;
        ilo = std::numeric_limits<int>::min();
        
        current_statement__ = 4;
        ilo = std::max(0, (k - khalf));
        current_statement__ = 5;
        assign(q, cons_list(index_uni(k), nil_index_list()), 0.0,
          "assigning variable q");
        current_statement__ = 8;
        for (int i = ilo; i <= iup; ++i) {
          current_statement__ = 6;
          assign(q, cons_list(index_uni(k), nil_index_list()),
            (q[(k - 1)] + (p[((i + 1) - 1)] * p[((k - i) - 1)])),
            "assigning variable q");}}
      current_statement__ = 2;
      current_statement__ = 2;
      check_simplex(function__, "q", q);
      {
        current_statement__ = 11;
        lp_accum__.add(dirichlet_lpdf<false>(p, alpha));
        current_statement__ = 19;
        for (int i = 1; i <= N; ++i) {
          current_statement__ = 12;
          validate_non_negative_index("lq", "K + 1", (K + 1));
          Eigen::Matrix<local_scalar_t__, -1, 1> lq;
          lq = Eigen::Matrix<local_scalar_t__, -1, 1>((K + 1));
          stan::math::fill(lq, DUMMY_VAR__);
          
          current_statement__ = 16;
          for (int j = 1; j <= (K + 1); ++j) {
            current_statement__ = 14;
            assign(lq, cons_list(index_uni(j), nil_index_list()),
              (rvalue(gl,
                 cons_list(index_uni(i),
                   cons_list(index_uni(j), nil_index_list())), "gl") +
                stan::math::log(q[(j - 1)])), "assigning variable lq");}
          current_statement__ = 17;
          lp_accum__.add(log_sum_exp(lq));}
      }
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    lp_accum__.add(lp__);
    return lp_accum__.sum();
    } // log_prob_impl() 
    
  template <typename RNG, typename VecR, typename VecI, typename VecVar, stan::require_vector_like_vt<std::is_floating_point, VecR>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr, stan::require_std_vector_vt<std::is_floating_point, VecVar>* = nullptr>
  inline void write_array_impl(RNG& base_rng__, VecR& params_r__,
                               VecI& params_i__, VecVar& vars__,
                               const bool emit_transformed_parameters__ = true,
                               const bool emit_generated_quantities__ = true,
                               std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.resize(0);
    stan::io::reader<local_scalar_t__> in__(params_r__, params_i__);
    static const char* function__ = "model_gl_null_namespace::write_array";
(void) function__;  // suppress unused var warning
    (void) function__;  // suppress unused var warning
    double lp__ = 0.0;
    (void) lp__;  // dummy to suppress unused var warning
    stan::math::accumulator<double> lp_accum__;
    local_scalar_t__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
    (void) DUMMY_VAR__;  // suppress unused var warning
    
    try {
      Eigen::Matrix<double, -1, 1> p;
      p = Eigen::Matrix<double, -1, 1>(khalf);
      stan::math::fill(p, std::numeric_limits<double>::quiet_NaN());
      
      Eigen::Matrix<local_scalar_t__, -1, 1> p_in__;
      p_in__ = Eigen::Matrix<local_scalar_t__, -1, 1>((khalf - 1));
      stan::math::fill(p_in__, DUMMY_VAR__);
      
      current_statement__ = 1;
      p_in__ = in__.vector((khalf - 1));
      current_statement__ = 1;
      assign(p, nil_index_list(), stan::math::simplex_constrain(p_in__),
        "assigning variable p");
      Eigen::Matrix<double, -1, 1> q;
      q = Eigen::Matrix<double, -1, 1>(q_1dim__);
      stan::math::fill(q, std::numeric_limits<double>::quiet_NaN());
      
      for (int sym1__ = 1; sym1__ <= khalf; ++sym1__) {
        vars__.emplace_back(p[(sym1__ - 1)]);}
      if (logical_negation((primitive_value(emit_transformed_parameters__) ||
            primitive_value(emit_generated_quantities__)))) {
        return ;
      } 
      current_statement__ = 10;
      for (int k = 1; k <= (K + 1); ++k) {
        int iup;
        iup = std::numeric_limits<int>::min();
        
        current_statement__ = 3;
        iup = std::min((k - 1), (khalf - 1));
        int ilo;
        ilo = std::numeric_limits<int>::min();
        
        current_statement__ = 4;
        ilo = std::max(0, (k - khalf));
        current_statement__ = 5;
        assign(q, cons_list(index_uni(k), nil_index_list()), 0.0,
          "assigning variable q");
        current_statement__ = 8;
        for (int i = ilo; i <= iup; ++i) {
          current_statement__ = 6;
          assign(q, cons_list(index_uni(k), nil_index_list()),
            (q[(k - 1)] + (p[((i + 1) - 1)] * p[((k - i) - 1)])),
            "assigning variable q");}}
      current_statement__ = 2;
      current_statement__ = 2;
      check_simplex(function__, "q", q);
      if (emit_transformed_parameters__) {
        for (int sym1__ = 1; sym1__ <= q_1dim__; ++sym1__) {
          vars__.emplace_back(q[(sym1__ - 1)]);}
      } 
      if (logical_negation(emit_generated_quantities__)) {
        return ;
      } 
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // write_array_impl() 
    
  template <typename VecVar, typename VecI, stan::require_std_vector_t<VecVar>* = nullptr, stan::require_vector_like_vt<std::is_integral, VecI>* = nullptr>
  inline void transform_inits_impl(const stan::io::var_context& context__,
                                   VecI& params_i__, VecVar& vars__,
                                   std::ostream* pstream__ = nullptr) const {
    using local_scalar_t__ = double;
    vars__.clear();
    vars__.reserve(num_params_r__);
    
    try {
      int pos__;
      pos__ = std::numeric_limits<int>::min();
      
      pos__ = 1;
      Eigen::Matrix<double, -1, 1> p;
      p = Eigen::Matrix<double, -1, 1>(khalf);
      stan::math::fill(p, std::numeric_limits<double>::quiet_NaN());
      
      {
        std::vector<local_scalar_t__> p_flat__;
        current_statement__ = 1;
        assign(p_flat__, nil_index_list(), context__.vals_r("p"),
          "assigning variable p_flat__");
        current_statement__ = 1;
        pos__ = 1;
        current_statement__ = 1;
        for (int sym1__ = 1; sym1__ <= khalf; ++sym1__) {
          current_statement__ = 1;
          assign(p, cons_list(index_uni(sym1__), nil_index_list()),
            p_flat__[(pos__ - 1)], "assigning variable p");
          current_statement__ = 1;
          pos__ = (pos__ + 1);}
      }
      Eigen::Matrix<double, -1, 1> p_free__;
      p_free__ = Eigen::Matrix<double, -1, 1>((khalf - 1));
      stan::math::fill(p_free__, std::numeric_limits<double>::quiet_NaN());
      
      current_statement__ = 1;
      assign(p_free__, nil_index_list(), stan::math::simplex_free(p),
        "assigning variable p_free__");
      for (int sym1__ = 1; sym1__ <= (khalf - 1); ++sym1__) {
        vars__.emplace_back(p_free__[(sym1__ - 1)]);}
    } catch (const std::exception& e) {
      stan::lang::rethrow_located(e, locations_array__[current_statement__]);
      // Next line prevents compiler griping about no return
      throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***"); 
    }
    } // transform_inits_impl() 
    
  inline void get_param_names(std::vector<std::string>& names__) const {
    
    names__.clear();
    names__.emplace_back("p");
    names__.emplace_back("q");
    } // get_param_names() 
    
  inline void get_dims(std::vector<std::vector<size_t>>& dimss__) const {
    dimss__.clear();
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(khalf)});
    
    dimss__.emplace_back(std::vector<size_t>{static_cast<size_t>(q_1dim__)});
    
    } // get_dims() 
    
  inline void constrained_param_names(
                                      std::vector<std::string>& param_names__,
                                      bool emit_transformed_parameters__ = true,
                                      bool emit_generated_quantities__ = true) const
    final {
    
    for (int sym1__ = 1; sym1__ <= khalf; ++sym1__) {
      {
        param_names__.emplace_back(std::string() + "p" + '.' + std::to_string(sym1__));
      }}
    if (emit_transformed_parameters__) {
      for (int sym1__ = 1; sym1__ <= q_1dim__; ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "q" + '.' + std::to_string(sym1__));
        }}
    }
    
    if (emit_generated_quantities__) {
      
    }
    
    } // constrained_param_names() 
    
  inline void unconstrained_param_names(
                                        std::vector<std::string>& param_names__,
                                        bool emit_transformed_parameters__ = true,
                                        bool emit_generated_quantities__ = true) const
    final {
    
    for (int sym1__ = 1; sym1__ <= (khalf - 1); ++sym1__) {
      {
        param_names__.emplace_back(std::string() + "p" + '.' + std::to_string(sym1__));
      }}
    if (emit_transformed_parameters__) {
      for (int sym1__ = 1; sym1__ <= (q_1dim__ - 1); ++sym1__) {
        {
          param_names__.emplace_back(std::string() + "q" + '.' + std::to_string(sym1__));
        }}
    }
    
    if (emit_generated_quantities__) {
      
    }
    
    } // unconstrained_param_names() 
    
  inline std::string get_constrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"p\",\"type\":{\"name\":\"vector\",\"length\":" << khalf << "},\"block\":\"parameters\"},{\"name\":\"q\",\"type\":{\"name\":\"vector\",\"length\":" << q_1dim__ << "},\"block\":\"transformed_parameters\"}]";
    return s__.str();
    } // get_constrained_sizedtypes() 
    
  inline std::string get_unconstrained_sizedtypes() const {
    stringstream s__;
    s__ << "[{\"name\":\"p\",\"type\":{\"name\":\"vector\",\"length\":" << (khalf - 1) << "},\"block\":\"parameters\"},{\"name\":\"q\",\"type\":{\"name\":\"vector\",\"length\":" << (q_1dim__ - 1) << "},\"block\":\"transformed_parameters\"}]";
    return s__.str();
    } // get_unconstrained_sizedtypes() 
    
  
    // Begin method overload boilerplate
    template <typename RNG>
    inline void write_array(RNG& base_rng,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                            Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                            const bool emit_transformed_parameters = true,
                            const bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      std::vector<double> vars_vec(vars.size());
      std::vector<int> params_i;
      write_array_impl(base_rng, params_r, params_i, vars_vec,
          emit_transformed_parameters, emit_generated_quantities, pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i) {
        vars.coeffRef(i) = vars_vec[i];
      }
    }
    template <typename RNG>
    inline void write_array(RNG& base_rng, std::vector<double>& params_r,
                            std::vector<int>& params_i,
                            std::vector<double>& vars,
                            bool emit_transformed_parameters = true,
                            bool emit_generated_quantities = true,
                            std::ostream* pstream = nullptr) const {
      write_array_impl(base_rng, params_r, params_i, vars, emit_transformed_parameters, emit_generated_quantities, pstream);
    }
    template <bool propto__, bool jacobian__, typename T_>
    inline T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
                       std::ostream* pstream = nullptr) const {
      Eigen::Matrix<int, -1, 1> params_i;
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }
    template <bool propto__, bool jacobian__, typename T__>
    inline T__ log_prob(std::vector<T__>& params_r,
                        std::vector<int>& params_i,
                        std::ostream* pstream = nullptr) const {
      return log_prob_impl<propto__, jacobian__>(params_r, params_i, pstream);
    }
  
    inline void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double, Eigen::Dynamic, 1>& params_r,
                         std::ostream* pstream = nullptr) const final {
      std::vector<double> params_r_vec(params_r.size());
      std::vector<int> params_i;
      transform_inits_impl(context, params_i, params_r_vec, pstream);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i) {
        params_r.coeffRef(i) = params_r_vec[i];
      }
    }
    inline void transform_inits(const stan::io::var_context& context,
                                std::vector<int>& params_i,
                                std::vector<double>& vars,
                                std::ostream* pstream = nullptr) const final {
      transform_inits_impl(context, params_i, vars, pstream);
    }        
};
}
using stan_model = model_gl_null_namespace::model_gl_null;
#ifndef USING_R
// Boilerplate
stan::model::model_base& new_model(
        stan::io::var_context& data_context,
        unsigned int seed,
        std::ostream* msg_stream) {
  stan_model* m = new stan_model(data_context, seed, msg_stream);
  return *m;
}
stan::math::profile_map& get_stan_profile_data() {
  return model_gl_null_namespace::profiles__;
}
#endif
#endif
